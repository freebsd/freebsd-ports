# New ports collection makefile for: 	epic4
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $FreeBSD$
#

PORTNAME=	epic4
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.prbh.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.parodius.com/pub/epic/EPIC4-PRODUCTION/ \
		http://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.eu.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/ \
		ftp://totem.fix.no/pub/mirrors/epic/EPIC4-PRODUCTION/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-help-20050315.tar.gz

MAINTAINER=	josh@tcbug.org
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

CONFLICTS=	epic5-[0-9]*

GNU_CONFIGURE=	yes
MAN1=		epic.1
USE_OPENSSL=	yes

OPTIONS=	IPV6	"IPv6 support"		on \
		TCL	"TCL support"		on \
		PERL	"Perl scripting support" off

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
.endif

##  WITH_PERL:      enable perl5 support (requires perl 5.6.1 or newer)
#
# The path provided to --with-perl is needed, since the configure script
# looks for libperl.so in places very specific to Linux.  Possibly a
# patch to configure would be a better idea, but we need to rely on
# SITE_PERL and PERL_VER to create the path.
#
.if defined(WITH_PERL)
.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or newer; we recommend perl 5.8.5
.endif
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl=${SITE_PERL}/../../${PERL_VER}/mach/CORE
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
.endif

.include <bsd.port.post.mk>
