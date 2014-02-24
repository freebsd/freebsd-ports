# $FreeBSD$

PORTNAME=	monodevelop-database
PORTVERSION=	4.2.2
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	mono@FreeBSD.org
COMMENT=	MonoDevelop database support

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gtksharp20
MAKE_JOBS_UNSAFE=yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
