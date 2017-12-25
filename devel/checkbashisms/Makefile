# $FreeBSD$

PORTNAME=	checkbashisms
PORTVERSION=	2.17.11
CATEGORIES=	devel perl5
MASTER_SITES=	DEBIAN/pool/main/d/devscripts/
DISTNAME=	devscripts_${PORTVERSION}

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Check for the presence of bashisms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:xz
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/devscripts-${PORTVERSION}
SHEBANG_FILES=	scripts/checkbashisms.pl

PLIST_FILES=	bin/checkbashisms \
		man/man1/checkbashisms.1.gz \
		etc/bash_completion.d/_checkbashisms.bash

post-patch:
	@${REINPLACE_CMD} -e 's|###VERSION###|${PORTVERSION}|' ${WRKSRC}/scripts/checkbashisms.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/checkbashisms.pl \
	    ${STAGEDIR}${PREFIX}/bin/checkbashisms
	${INSTALL_MAN} ${WRKSRC}/scripts/checkbashisms.1 \
	    ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/checkbashisms.bash_completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/_checkbashisms.bash

.include <bsd.port.mk>
