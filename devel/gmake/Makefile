# Created by: jkh
# $FreeBSD$

PORTNAME=	gmake
PORTVERSION=	4.3
CATEGORIES=	devel
MASTER_SITES=	GNU/make
DISTNAME=	make-${PORTVERSION}

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU version of 'make' utility

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g \
		--without-guile

USES=		cpe tar:lz
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

INFO=		make

.include <bsd.port.mk>
