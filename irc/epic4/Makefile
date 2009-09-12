# New ports collection makefile for: 	epic4
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $FreeBSD$
#

PORTNAME=	epic4
PORTVERSION=	2.10.1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/ \
		http://tehran.lain.pl/epic-mirror/EPIC4-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.parodius.com/pub/epic/EPIC4-PRODUCTION/ \
		http://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.eu.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-help-20050315.tar.bz2

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

CONFLICTS=	epic5-0.[0-2]*

GNU_CONFIGURE=	yes
MAN1=		epic.1
USE_OPENSSL=	yes
SUB_FILES=	pkg-message
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
USE_BZIP2=	yes
WANT_PERL=	yes
CFLAGS:=	${CFLAGS:C/-O2/-g -O/g}

OPTIONS=	IPV6	"IPv6 support"		on \
		TCL	"TCL support"		on \
		PERL    "Perl scripting support" on \
		SOCKS5	"Enable SOCKS5 proxy support" off \
		SSL     "Enable SSL support" on \
		TERMCAP	"Refuse to use terminfo/ncurses" off

.include <bsd.port.pre.mk>

##  WITHOUT_IPV6:   disable IPv6 support
#
.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--without-ipv6
.endif

##  WITH_TCL:       enable Tcl support
#
.if !defined(WITHOUT_TCL)
LIB_DEPENDS+=		tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl
.else
CONFIGURE_ARGS+=	--without-tcl
.endif

##  WITH_PERL:      enable perl5 support (requires perl 5.6.1 or newer)
#
# The path provided to --with-perl is needed, since the configure script
# looks for libperl.so in places very specific to Linux.  Possibly a
# patch to configure would be a better idea, but we need to rely on
# SITE_PERL and PERL_VERSION to create the path.
#
.if defined(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl=${SITE_PERL}/../../${PERL_VERSION}/mach/CORE
.else
CONFIGURE_ARGS+=	--without-perl
.endif

## WITH_SOCKS5:                enable SOCKS5 support
#
.if defined(WITH_SOCKS5)
.if exists(${LOCALBASE}/lib/libdsocks.so)
BROKEN=	Optional socks5 support will only build against net/socks5 which conflicts with net/dante
.endif
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--with-socks5=${LOCALBASE}/include
.endif

## WITH_SSL            enable SSL support
#
.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

## WITH_TERMCAP                forceably refuse to use terminfo/ncurses
#
.if defined(WITH_TERMCAP)
CONFIGURE_ARGS+=	--with-termcap
.endif

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

post-patch:
	@${RM} ${WRKDIR}/help/Makefile

post-install:
	@${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/epic/help
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in BUG_FORM COPYRIGHT KNOWNBUGS README UPDATES VOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
