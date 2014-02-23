# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	monodevelop
PORTVERSION=	4.2.2
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	mono@FreeBSD.org
COMMENT=	IDE for the .NET platform

BUILD_DEPENDS=	mautil:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS=	${LOCALBASE}/lib/libgdiplus.a:${PORTSDIR}/x11-toolkits/libgdiplus \
		exctags:${PORTSDIR}/devel/ctags \
		mautil:${PORTSDIR}/devel/mono-addins

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GNOME=	gtksharp20 gnomesharp20
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake pathfix shared-mime-info
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	MONOEXT GIT SVN
OPTIONS_DEFAULT=MONOEXT GIT SVN
MONOEXT_DESC=	Extensions for Mono development
GIT_DESC=	git support

MONOEXT_CONFIGURE_ENABLE=monoextensions
GIT_CONFIGURE_ENABLE=git
GIT_RUN_DEPENDS=git:${PORTSDIR}/devel/git
SVN_CONFIGURE_ENABLE=subversion
SVN_RUN_DEPENDS=svn:${PORTSDIR}/devel/subversion

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

post-patch:
	@${REINPLACE_CMD} -e 's|[(]gnome_data[)]/mime$$|(prefix)/share/mime|g ; \
		s|[(]gnome_data[)]/mime/packages$$|(prefix)/share/mime/packages|g ; \
		s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/monodevelop.in \
		${WRKSRC}/mdtool.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
