# Created by: Josh Paetzel <josh@tcbug.org>
# $FreeBSD$

PORTNAME=	epic5
PORTVERSION=	1.1.6
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ftp.epicsol.org/pub/epic/EPIC5-PRODUCTION/ \
		http://tehran.lain.pl/epic-mirror/EPIC5-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/EPIC5-PRODUCTION/ \
		http://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC5-PRODUCTION/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
MAN1=		epic5.1
USE_OPENSSL=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
USE_BZIP2=	yes
WANT_PERL=	yes
CFLAGS:=	${CFLAGS:C/-O2/-g -O/g}

OPTIONS_DEFINE=	IPV6 TCL PERL SSL TERMCAP DOCS RUBY
OPTIONS_DEFAULT=	TCL PERL SSL RUBY
TERMCAP_DESC=	Refuse to use terminfo/ncurses

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if ${PORT_OPTIONS:MTCL}
LIB_DEPENDS+=		tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl
.else
CONFIGURE_ARGS+=	--without-tcl
.endif

#  enable perl5 support (requires perl 5.6.1 or newer)
#
.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
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

CONFIGURE_ARGS+=	--with-iconv=${LOCALBASE}
USES=		iconv

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in BUG_FORM COPYRIGHT KNOWNBUGS README UPDATES VOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
