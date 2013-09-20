# Created by: numisemis at yahoo dot com
# $FreeBSD$

PORTNAME=	julius
PORTVERSION=	4.1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	julius/37582

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Large Vocabulary Continuous Speech Recognition Engine

BUILD_DEPENDS=	ja-p5-Jcode>=0:${PORTSDIR}/japanese/p5-Jcode
RUN_DEPENDS=	ja-p5-Jcode>=0:${PORTSDIR}/japanese/p5-Jcode

MANCOMPRESSED=	no
GNU_CONFIGURE=	yes
USES=		iconv
NO_STAGE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
MANLANG=	"" ja
MAN1=	accept_check.1 \
	adinrec.1 \
	adintool.1 \
	dfa_determinize.1 \
	dfa_minimize.1 \
	generate-ngram.1 \
	generate.1 \
	gram2sapixml.pl.1 \
	jclient.pl.1 \
	jcontrol.1 \
	julius.1 \
	mkbingram.1 \
	mkbinhmm.1 \
	mkbinhmmlist.1 \
	mkdfa.pl.1 \
	mkgshmm.1 \
	mkss.1 \
	nextword.1

post-configure:
	@${FIND} ${WRKSRC} -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -E -e "s|INSTALL=(\.\./)+|INSTALL=install -o root -g wheel|"
	@${FIND} ${WRKSRC} -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -E -e "s|install  -s|install|"
	@${REINPLACE_CMD} -E -e "s|man1/ja|ja/man1|" ${WRKSRC}/man/Makefile

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/accept_check
	@${STRIP_CMD} ${PREFIX}/bin/adinrec
	@${STRIP_CMD} ${PREFIX}/bin/adintool
	@${STRIP_CMD} ${PREFIX}/bin/dfa_determinize
	@${STRIP_CMD} ${PREFIX}/bin/dfa_minimize
	@${STRIP_CMD} ${PREFIX}/bin/generate-ngram
	@${STRIP_CMD} ${PREFIX}/bin/generate
	@${STRIP_CMD} ${PREFIX}/bin/jcontrol
	@${STRIP_CMD} ${PREFIX}/bin/julius
	@${STRIP_CMD} ${PREFIX}/bin/mkbingram
	@${STRIP_CMD} ${PREFIX}/bin/mkbinhmm
	@${STRIP_CMD} ${PREFIX}/bin/mkbinhmmlist
	@${STRIP_CMD} ${PREFIX}/bin/mkfa
	@${STRIP_CMD} ${PREFIX}/bin/mkss
	@${STRIP_CMD} ${PREFIX}/bin/nextword

.include <bsd.port.mk>
