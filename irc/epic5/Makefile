# New ports collection makefile for: 	epic4
# Date created:		11 November 1998
# Whom:			Ben Hutchinson <benhutch@xfiles.org.uk>
#
# $FreeBSD$
#

PORTNAME=	epic4
PORTVERSION=	2.0
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/ \
		ftp://ftp.parodius.com/pub/epic/EPIC4-PRODUCTION/ \
		ftp://planetmirror.com/pub/irc/epic/ \
		ftp://ftp.eu.uu.net/pub/unix/irc/epic/ \
		ftp://totem.fix.no/pub/mirrors/epic/ \
		ftp://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTFILE_HELP}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

USE_OPENSSL=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-tcl

.if defined(WITH_TCL)
LIB_DEPENDS=		tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl
.endif

MAN1=		epic.1
DISTFILE_HELP=	${PORTNAME}-help-20040308.tar.gz

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

post-patch:
	@${RM} ${WRKDIR}/help/Makefile

post-install:
	@${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/epic/help
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README BUG_FORM UPDATES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
