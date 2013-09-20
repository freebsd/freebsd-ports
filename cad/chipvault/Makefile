# Created by: ijliao
# $FreeBSD$

PORTNAME=	chipvault
PORTVERSION=	200607
CATEGORIES=	cad
MASTER_SITES=	http://chipvault.sourceforge.net/
DISTNAME=	cv.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A project organizer for VHDL and Verilog RTL hardware designs

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	> ${DISTNAME}
NO_BUILD=	yes
PLIST_FILES=	bin/cv
USES=		perl5
USE_PERL5=	run

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cv.pl ${PREFIX}/bin/cv

.include <bsd.port.mk>
