# $FreeBSD$

PORTNAME=	checkbashisms
PORTVERSION=	2.12.6
CATEGORIES=	devel perl5
MASTER_SITES=	DEBIAN/pool/main/d/devscripts/
DISTNAME=	devscripts_${PORTVERSION}

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Debian script that checks for bash-isms

LICENSE=	GPLv2

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/devscripts-${PORTVERSION}
SHEBANG_FILES=	scripts/checkbashisms.pl

PLIST_FILES=	bin/checkbashisms \
		man/man1/checkbashisms.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|###VERSION###|${PORTVERSION}|' ${WRKSRC}/scripts/checkbashisms.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/checkbashisms.pl \
	    ${STAGEDIR}${PREFIX}/bin/checkbashisms
	${INSTALL_MAN} ${WRKSRC}/scripts/checkbashisms.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
