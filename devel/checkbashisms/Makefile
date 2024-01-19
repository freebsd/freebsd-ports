PORTNAME=	checkbashisms
DISTVERSION=	2.22.2
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	DEBIAN/pool/main/d/devscripts/
DISTNAME=	devscripts_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Check for the presence of bashisms
WWW=		https://packages.qa.debian.org/d/devscripts.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:xz
USE_PERL5=	run

SHEBANG_FILES=	scripts/checkbashisms.pl

NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^d\.d+\.d
WRKSRC=		${WRKDIR}/devscripts-${PORTVERSION}

PLIST_FILES=	bin/checkbashisms \
		etc/bash_completion.d/_checkbashisms.bash \
		share/man/man1/checkbashisms.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|###VERSION###|${PORTVERSION}|' \
		${WRKSRC}/scripts/checkbashisms.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/checkbashisms.pl \
		${STAGEDIR}${PREFIX}/bin/checkbashisms
	${INSTALL_MAN} ${WRKSRC}/scripts/checkbashisms.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/checkbashisms.bash_completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/_checkbashisms.bash

.include <bsd.port.mk>
