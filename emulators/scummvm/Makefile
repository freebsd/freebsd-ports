# New ports collection makefile for:	scummvm
# Date created:				Tue Sep  2 23:34:32 BST 2003
# Whom:				Alex Trull <alexander@trull.com>
#
# $FreeBSD$
#

PORTNAME=	scummvm
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alexander@trull.com
COMMENT=	Free implementation of LucasArts S.C.U.M.M. interpreter

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
USE_SDL=	yes

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
