# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	kcode
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.irori.org/dl/tool/
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Handy utility to show codepoint information of given characters

USES=		shebangfix perl5
USE_PERL5=	extract run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SHEBANG_FILES=	kcode

PLIST_FILES=	bin/kcode man/ja/man1/kcode.1.gz

RUN_DEPENDS=	ja-p5-Jcode>=0:japanese/p5-Jcode

do-extract:
	${MKDIR} ${WRKSRC}
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > ${WRKSRC}/kcode

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kcode ${STAGEDIR}${PREFIX}/bin
	pod2man ${WRKSRC}/kcode ${WRKSRC}/kcode.1
	${INSTALL_MAN} ${WRKSRC}/kcode.1 ${STAGEDIR}${MANPREFIX}/man/ja/man1

.include <bsd.port.mk>
