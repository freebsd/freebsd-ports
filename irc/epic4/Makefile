# Created by: Ben Hutchinson <benhutch@xfiles.org.uk>
# $FreeBSD$

PORTNAME=	epic4
PORTVERSION=	2.10.2
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/ \
		http://tehran.lain.pl/epic-mirror/EPIC4-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/EPIC4-PRODUCTION/ \
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
CFLAGS:=	${CFLAGS:C/-O2/-g -O/g}

OPTIONS_DEFINE=	IPV6 TCL PERL SSL TERMCAP DOCS
OPTIONS_DEFAULT=	TCL PERL SSL
TERMCAP_DESC=	Refuse to use terminfo/ncurses

NO_STAGE=	yes
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
# The path provided to --with-perl is needed, since the configure script
# looks for libperl.so in places very specific to Linux.  Possibly a
# patch to configure would be a better idea, but we need to rely on
# SITE_PERL and PERL_VERSION to create the path.
#
.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=	--with-perl=${SITE_PERL}/../../${PERL_VERSION}/mach/CORE
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if ${PORT_OPTIONS:MTERMCAP}
CONFIGURE_ARGS+=	--with-termcap
.endif

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

post-patch:
	@${RM} ${WRKDIR}/help/Makefile

post-install:
	@${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/epic/help
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in BUG_FORM COPYRIGHT KNOWNBUGS README UPDATES VOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
