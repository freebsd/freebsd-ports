# Created by: Ben Hutchinson <benhutch@xfiles.org.uk>
# $FreeBSD$

PORTNAME=	epic4
PORTVERSION=	2.10.7
CATEGORIES=	irc
MASTER_SITES=	http://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/ \
		http://ftp.cc.uoc.gr/mirrors/irc/epic/EPIC4-PRODUCTION/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-help-20050315.tar.bz2

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	(E)nhanced (P)rogrammable (I)RC-II (C)lient

LICENSE=	BSD3CLAUSE

USES=		ncurses tar:xz

CONFLICTS=	epic5-0.[0-2]*

GNU_CONFIGURE=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
CFLAGS:=	${CFLAGS:C/-O2/-g -O/g}

OPTIONS_DEFINE=	IPV6 TCL PERL SSL DOCS
OPTIONS_DEFAULT=	TCL PERL SSL

IPV6_CONFIGURE_WITH=	ipv6

SSL_CONFIGURE_WITH=	ssl="${OPENSSLBASE}"
SSL_USES=		ssl

TCL_CONFIGURE_WITH=	tcl="${TCL_LIBDIR}"
TCL_USES=		tcl

PERL_CONFIGURE_WITH=	perl
PERL_USES=		perl5

.include <bsd.port.options.mk>

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
