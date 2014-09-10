# Created by: TANAKA Hiroyuki <kattyo@abk.nu>
# $FreeBSD$

PORTNAME=	xtr
PORTVERSION=	1.50e.0.2
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.abk.nu/pub/redist/xtr/
DISTNAME=	${PORTNAME}1.50e-0.2
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese text formatting processor

USE_CSTD=	c89
USE_GCC=	yes

GNU_CONFIGURE=	yes

NO_CDROM=	Need to obtain permission for commercial redistribution

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${ECHO_MSG} "===>  Converting Kanji code for ${DISTNAME}"
	@(cd ${WRKSRC} && $(SH) EUCsetup )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xtr ${STAGEDIR}${PREFIX}/bin/xtr
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README doc/xtr.doc
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/*.xtr ${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
