# Created by: bms@FreeBSD.org
# $FreeBSD$

PORTNAME=		p4genpatch
PORTVERSION=		1
CATEGORIES=		devel
MASTER_SITES=		#
DISTFILES=

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Helper scripts for generating RCS patches from Perforce

RUN_DEPENDS=		p4:${PORTSDIR}/devel/p4

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

USES=			shebangfix
USE_PERL5=		yes

SCRIPTS=		bin/p4genpatch bin/p4d2p
PLIST_FILES=		${SCRIPTS}

SHEBANG_FILES=		${SCRIPTS}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -r ${FILESDIR}/bin ${WRKSRC}

do-install:
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
