# New ports collection makefile for:	scummvm
# Date created:				Tue Mar 26 13:05:21 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	scummvm
PORTVERSION=	0.4.1
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Free implementation of LucasArts S.C.U.M.M. interpreter

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		mad.1:${PORTSDIR}/audio/mad

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN6=		scummvm.6

pre-patch:
	@${FIND} -E ${WRKSRC} -type f -iregex ".*\.(cpp|h|txt)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;
	@${REINPLACE_CMD} -e 's|\r\n|\n|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's@sdl-config@sdl11-config@g' \
		${WRKSRC}/backends/sdl/build.rules

post-configure:
	@${REINPLACE_CMD} -e 's@:= -g -O@+= ${CFLAGS}@' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/scummvm.6 ${PREFIX}/man/man6

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in README
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
