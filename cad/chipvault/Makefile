PORTNAME=	chipvault
PORTVERSION=	200607
CATEGORIES=	cad
MASTER_SITES=	http://chipvault.sourceforge.net/
DISTNAME=	cv.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Project organizer for VHDL and Verilog RTL hardware designs

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	> ${DISTNAME}
NO_BUILD=	yes
PLIST_FILES=	bin/cv
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	cv.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cv.pl ${STAGEDIR}${PREFIX}/bin/cv

.include <bsd.port.mk>
