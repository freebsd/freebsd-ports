# Created by: Josh Paetzel <josh@tcbug.org>
# $FreeBSD$

PORTNAME=	epic5
PORTVERSION=	1.1.10
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ftp.epicsol.org/pub/epic/EPIC5-PRODUCTION/ \
		http://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC5-PRODUCTION/

MAINTAINER=	mp39590@gmail.com
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
USE_BZIP2=	yes
CFLAGS:=	${CFLAGS:C/-O2/-g -O/g}

OPTIONS_DEFINE=	IPV6 TCL PERL TERMCAP DOCS RUBY
OPTIONS_DEFAULT=	TCL PERL RUBY
TERMCAP_DESC=	Refuse to use terminfo/ncurses

CONFIGURE_ARGS+=--with-iconv=${ICONV_PREFIX}
USES=		iconv

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=		tcl
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}/tclConfig.sh
.else
CONFIGURE_ARGS+=	--without-tcl
.endif

#  enable perl5 support (requires perl 5.6.1 or newer)
#
.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=	--with-perl
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
CONFIGURE_ARGS+=	--with-ruby
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--without-ruby
.endif

.if ${PORT_OPTIONS:MTERMCAP}
CONFIGURE_ARGS+=	--with-termcap
.endif

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUG_FORM COPYRIGHT KNOWNBUGS README UPDATES VOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 901000
IGNORE=	requires xlocale support for compilation
.endif

.include <bsd.port.post.mk>
