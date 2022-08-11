PORTNAME=	c2t
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/:file  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/x-win/cxterm/dict/gb/:dict
DISTFILES=	c2t.tar.gz:file TONEPY.tit:dict

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translates GB/Big5 encoding to tone pinyin

NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	c2t.tar.gz

CFLAGS+=	-Dregister=

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/chinese/gb
	${INSTALL_PROGRAM} ${WRKSRC}/c2t ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/TONEPY.tit ${STAGEDIR}${PREFIX}/share/chinese/gb
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
