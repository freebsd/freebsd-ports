# New ports collection makefile for:	rayshade
# Date created:		21 January 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	rayshade
PORTVERSION=	4.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://graphics.stanford.edu/pub/rayshade/	\
		ftp://ftp.princeton.edu/pub/Graphics/rayshade.4.0/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	$(LOCALBASE)/lib/librle.a:${PORTSDIR}/graphics/urt

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	< ${WRKDIR}/config.ans
ALL_TARGET=

pre-configure:
	$(SED) -e "s,@CFLAGS@,${CFLAGS}," < ${FILESDIR}/config.ans > \
		${WRKDIR}/config.ans

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/rayshade/rayshade $(PREFIX)/bin
# THIS ARE NOT USED BY ANY PORT
#	$(INSTALL_DATA) $(WRKSRC)/libray/libray.a $(PREFIX)/lib
#	$(INSTALL_DATA) $(WRKSRC)/libshade/libshade.a $(PREFIX)/lib
	$(MKDIR) $(PREFIX)/share/doc/rayshade
	$(INSTALL_DATA) $(WRKSRC)/Doc/Guide/* $(PREFIX)/share/doc/rayshade
	$(INSTALL_DATA) $(WRKSRC)/Doc/quickref.txt $(PREFIX)/share/doc/rayshade
	$(MKDIR) $(PREFIX)/share/examples/rayshade
	$(INSTALL_DATA) $(WRKSRC)/Examples/* $(PREFIX)/share/examples/rayshade

.include <bsd.port.mk>
