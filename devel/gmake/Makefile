PORTNAME=	make
DISTVERSION=	4.4.1
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU version of 'make' utility
WWW=		https://www.gnu.org/software/make/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:lz
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=g \
		--without-guile

INFO=		make

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
