# Ports collection Makefile for:	dasher
# Date created:				5 July 2003
# Whom:					lewiz <purple@lewiz.net>
#
# $FreeBSD$
#   $MCom: ports/accessibility/dasher/Makefile,v 1.18 2005/10/29 22:31:15 marcus Exp $
#

PORTNAME=	dasher
PORTVERSION=	3.2.18
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	accessibility editors x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/3.2
DIST_SUBDIR=	gnome2

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Information efficient text-entry interface

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier libgnomeui atspi \
		libwnck
WANT_GNOME=	yes
USE_AUTOTOOLS=	libtool:15:inc
INSTALLS_OMF=	yes
USE_REINPLACE=	yes
USE_GCC=	3.4+
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		dasher.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomespeech}!=""
USE_GNOME+=	gnomespeech
.else
CONFIGURE_ARGS+=--without-speech
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O2||g'

patch-autotools::
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.post.mk>
