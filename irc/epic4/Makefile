# New ports collection makefile for: 	epic4
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $FreeBSD$
#

PORTNAME=	epic4
PORTVERSION=	1.1.16
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-ALPHA/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-ALPHA/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTFILE_HELP}

MAINTAINER=	anders@andersa.net
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

USE_REINPLACE=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

MAN1=		epic.1
DISTFILE_HELP=	${PORTNAME}-help-20031106.tar.gz

post-patch:
	${REINPLACE_CMD} -e 's|8.3|8.4|g' ${WRKSRC}/configure
	${FIND} . -type d -name CVS | ${XARGS} ${RM} -rf
	${RM} ${WRKDIR}/help/Makefile

post-install:
	${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/epic/help

.include <bsd.port.mk>
