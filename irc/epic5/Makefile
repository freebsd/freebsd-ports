PORTNAME=	epic5
DISTVERSION=	3.0
CATEGORIES=	irc
MASTER_SITES=	https://ftp.epicsol.org/pub/epic/EPIC5-PRODUCTION/

MAINTAINER=	epic@dsllsn.net
COMMENT=	Enhanced Programmable IRC-II Client
WWW=		https://www.epicsol.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		iconv libarchive ncurses ssl tar:xz

GNU_CONFIGURE=	yes

COMMITID=	2140
PLIST_SUB+=	COMMITID=${COMMITID}

CONFIGURE_ARGS=	--with-iconv=${ICONV_PREFIX}

OPTIONS_DEFINE=		DOCS PERL PYTHON RUBY
OPTIONS_DEFAULT=	PYTHON

PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl

PYTHON_USES=		python gettext-runtime
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}-config
PYTHON_CONFIGURE_OFF=	--without-python

RUBY_USES=		ruby
RUBY_CONFIGURE_WITH=	ruby

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/epic5-${COMMITID}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/epic5-wserv4
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUG_FORM EPIC4-USERS-README FILES KNOWNBUGS README README-CRYPTO UPDATES WISHLIST
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
