# ex:ts=8
# Ports collection makefile for:	diacanvas2
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	diacanvas2
PORTVERSION=	0.13.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	diacanvas

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general drawing canvas from dia dialog editor

USE_GNOME=	gnomehack libgnomeprint libgnomeprintui libartlgpl2 \
		libgnomecanvas pygnome2
USE_PYTHON=	2.2+
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.if !defined(DISPLAY)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT}
CONFIGURE_ENV+=	DISPLAY=localhost:1001
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|unit_tests doc|unit_tests|g' ${WRKSRC}/Makefile.in

pre-configure:
.if exists(${WRKDIR}/.Xvfb.pid)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif
.if !defined(DISPLAY)
	#
	# This is a UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
.endif

post-configure:
.if !defined(DISPLAY)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ref/html/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ref/html/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
