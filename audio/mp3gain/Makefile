# New ports collection makefile for:	mp3gain
# Date created:		5 September 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	mp3gain
PORTVERSION=	1.3.2
CATEGORIES=	audio
MASTER_SITES=	http://www.mpex.net/software/mirror/ \
		http://www.speakeasy.net/~djkarmad/mp3gain/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//g}_src${EXTSUFFIX}

MAINTAINER=	corecode@corecode.ath.cx
COMMENT=	A tool to normalize the gain of mp3 files

PLIST_FILES=	bin/mp3gain
USE_REINPLACE=	yes
USE_ZIP=	yes

NO_WRKSUBDIR=	yes

MAKE_ENV=	PREFIX="${PREFIX}"

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s/`/usr/bin/printf '\r'`//"

post-patch:
	@${REINPLACE_CMD} -e '906,943s,/?,-h,;921,945s,/,-,g' ${WRKSRC}/mp3gain.c
	@${REINPLACE_CMD} -e 's,\\,/,' ${WRKSRC}/mpglibDBL/interface.h
	@${CP} ${FILESDIR}/Makefile.main ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/mpglibDBL/Makefile

.include <bsd.port.mk>
