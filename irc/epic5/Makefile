# New ports collection makefile for:   epic5
# Date created:                24 February 2005
# Whom:                        Josh Paetzel <josh@tcbug.org>
#
# $FreeBSD$
#

PORTNAME=	epic5
PORTVERSION=	1.0
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ftp.epicsol.org/pub/epic/EPIC5-PRODUCTION/ \
		http://tehran.lain.pl/epic-mirror/EPIC5-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/EPIC5-PRODUCTION/ \
		ftp://ftp.parodius.com/pub/epic/EPIC5-PRODUCTION/ \
		http://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC5-PRODUCTION/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
MAN1=		epic5.1
USE_OPENSSL=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
USE_BZIP2=	yes
CFLAGS:=	${CFLAGS:C/-O2/-g -O/g}

OPTIONS=	IPV6	"IPv6 support"		on \
		TCL	"TCL support"		on \
		PERL	"Perl scripting support" on \
		RUBY	"Ruby scripting support" on \
		TERMCAP	"Refuse to use terminfo/ncurses" off \
		ICONV	"Enable experimental iconv support" off

.include <bsd.port.pre.mk>

##  WITHOUT_IPV6:   disable IPv6 support
#
.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--without-ipv6
.endif

##  WITHOUT_TCL:    disable Tcl support
#
.if !defined(WITHOUT_TCL)
LIB_DEPENDS+=		tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl
.else
CONFIGURE_ARGS+=	--without-tcl
.endif

##  WITH_PERL:      enable perl5 support (requires perl 5.6.1 or newer)
#
.if defined(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
.else
CONFIGURE_ARGS+=	--without-perl
.endif

## WITH_RUBY:	enable ruby scripting support
#
.if defined(WITH_RUBY)
USE_RUBY=	yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
CONFIGURE_ARGS+=	--with-ruby
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--without-ruby
.endif

## WITH_TERMCAP	forecably refuse to use terminfo/ncurses
#
.if defined(WITH_TERMCAP)
CONFIGURE_ARGS+=	--with-termcap
.endif

## WITH_ICON	experimental iconv support
#
.if defined(WITH_ICONV)
LIB_DEPENDS+=	iconv:${PORTSDIR}/converters/libiconv
CONFIGURE_ARGS+=	--with-iconv
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in BUG_FORM COPYRIGHT KNOWNBUGS README UPDATES VOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
