# Created by: Ben Hutchinson <benhutch@xfiles.org.uk>
# $FreeBSD$

PORTNAME=	epic4
PORTVERSION=	2.10.5
PORTREVISION=	3
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

LICENSE=	BSD3CLAUSE

CONFLICTS=	epic5-0.[0-2]*

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
USES=		ncurses tar:bzip2
CFLAGS:=	${CFLAGS:C/-O2/-g -O/g}

OPTIONS_DEFINE=	IPV6 TCL PERL SSL DOCS
OPTIONS_DEFAULT=	TCL PERL SSL

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=			tcl
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
CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/lib/perl5/${PERL_VERSION}/${PERL_ARCH}/CORE
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -r

post-patch:
	@${RM} ${WRKDIR}/help/Makefile
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	@${CP} -R ${WRKDIR}/help/* ${STAGEDIR}${PREFIX}/share/epic/help
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUG_FORM COPYRIGHT KNOWNBUGS README UPDATES VOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
