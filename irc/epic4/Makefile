PORTNAME=	epic4
DISTVERSION=	3.0
CATEGORIES=	irc
MASTER_SITES=	https://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-help-20050315.tar.bz2

MAINTAINER=	epic@dsllsn.net
COMMENT=	(E)nhanced (P)rogrammable (I)RC-II (C)lient
WWW=		http://www.epicsol.org/

LICENSE=	BSD3CLAUSE

USES=		ncurses tar:xz

CONFLICTS=	epic5-0.[0-2]*

GNU_CONFIGURE=	yes

PLIST_SUB+=	DISTVERSION=${DISTVERSION}
CFLAGS:=	${CFLAGS:C/-O2/-O/g}
CFLAGS+=	-Wno-pointer-sign

OPTIONS_DEFINE=		IPV6 TCL PERL SSL DOCS
OPTIONS_DEFAULT=	TCL PERL SSL

IPV6_CONFIGURE_WITH=	ipv6

SSL_CONFIGURE_WITH=	ssl="${OPENSSLBASE}"
SSL_USES=		ssl

TCL_CONFIGURE_WITH=	tcl="${TCL_LIBDIR}"
TCL_USES=		tcl

PERL_CONFIGURE_WITH=	perl
PERL_USES=		perl5

.include <bsd.port.options.mk>

post-patch:
	@${RM} ${WRKDIR}/help/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/epic-EPIC4-${DISTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/wserv4
	@${CP} -R ${WRKDIR}/help/* ${STAGEDIR}${PREFIX}/share/epic/help
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUG_FORM COPYRIGHT KNOWNBUGS README UPDATES VOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
