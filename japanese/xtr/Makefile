PORTNAME=	xtr
PORTVERSION=	1.50e.0.2
PORTREVISION=	8
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.abk.nu/pub/redist/xtr/
DISTNAME=	${PORTNAME}1.50e-0.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese text formatting processor

# Converted from NO_CDROM
LICENSE=	xtr
LICENSE_NAME=	xtr
LICENSE_TEXT=	Need to obtain permission for commercial redistribution
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		tar:tgz
USE_CSTD=	c89
USE_GCC=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
	@${ECHO_MSG} "===>  Converting Kanji code for ${DISTNAME}"
	@(cd ${WRKSRC} && ${SH} EUCsetup )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xtr ${STAGEDIR}${PREFIX}/bin/xtr
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/*.xtr ${STAGEDIR}${PREFIX}/share/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README doc/xtr.doc
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
