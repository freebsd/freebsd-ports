# New ports collection makefile for:	yawmppp
# Date created:				07 Mar 2000
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	yawmppp
PORTVERSION=	2.0.1
CATEGORIES=	comms windowmaker
MASTER_SITES=	ftp://ftp.seul.org/pub/yawmppp/ \
		http://www.dcc.unicamp.br/~guazzibe/yawmppp/arch/

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GTK=	yes
CONFIGURE_ENV=	GTKCONFIG="${GTK_CONFIG}" CFLAGS="${CFLAGS} -I${X11BASE}/include"
CONFIGURE_ARGS=	--x-includes="${X11BASE}/include" \
		--x-libraries="${X11BASE}/lib"
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=		yawmppp.1x

pre-configure:
	${PERL} -pi -e "s@-g -O2@${CFLAGS}@g; s@-O2 -Wall@${CFLAGS} -Wall@g; \
			s@-O2@${CFLAGS}@g" ${WRKSRC}/*/Makefile.in \
			${WRKSRC}/configure ${WRKSRC}/*/*/Makefile.in

.include <bsd.port.mk>
