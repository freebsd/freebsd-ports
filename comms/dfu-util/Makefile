# New ports collection makefile for:	dfu-util
# Date created:		2008-02-04
# Whom:			Bruce Cran <bruce@cran.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dfu-util
DISTVERSION=	0.1.snap${SNAPDATE}
CATEGORIES=	comms
MASTER_SITES=	http://www.cran.org.uk/~brucec/software/

MAINTAINER=	bruce@cran.org.uk
COMMENT=	Device firmware update (DFU) USB programmer

MAN1=		dfu-util.1
PLIST_FILES=	bin/dfu-util
USE_AUTOTOOLS=	aclocal:19 automake:19 autoheader:262
AUTOMAKE_ARGS=	--add-missing --foreign --copy

SNAPDATE=	20090212
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800063
IGNORE=		requires new USB stack in FreeBSD 8
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dfu-util ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/dfu-util.1 ${MAN1PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
