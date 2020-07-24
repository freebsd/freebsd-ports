# Created by: numisemis at yahoo dot com
# $FreeBSD$

PORTNAME=	julius
PORTVERSION=	4.1.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	OSDN/julius

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Large Vocabulary Continuous Speech Recognition Engine

BUILD_DEPENDS=	ja-p5-Jcode>=0:japanese/p5-Jcode
RUN_DEPENDS=	ja-p5-Jcode>=0:japanese/p5-Jcode

GNU_CONFIGURE=	yes
USES=		iconv perl5 shebangfix
SHEBANG_FILES=	jclient-perl/jclient.pl

CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-Wno-return-type
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

post-configure:
	@${FIND} ${WRKSRC} -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -E \
		-e "s|INSTALL=(\.\./)+|INSTALL=install|" \
		-e "s|install  -s|install|; s|-m 555|-m 755|g" \
		-e "s,\{(bin|lib|include|man)dir,\(DESTDIR\)$$&,g" \
		-e "/(INSTALL|install)/ s,\{exec_prefix,\(DESTDIR\)$$&,g"
	@${REINPLACE_CMD} -E -e "s|man1/ja|ja/man1|" \
		-e "s| /usr/local| ${STAGEDIR}${PREFIX}|g" \
		${WRKSRC}/man/Makefile

post-install:
.for file in accept_check adinrec adintool dfa_determinize dfa_minimize \
generate-ngram generate jcontrol julius mkbingram mkbinhmm mkbinhmmlist mkfa \
mkss nextword
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
