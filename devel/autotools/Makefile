# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autotools
PORTVERSION=	20130627
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Autotools meta-port

RUN_DEPENDS=	libtoolize:devel/libtool \
		autoconf-2.13:devel/autoconf213 \
		autoconf-2.69:devel/autoconf \
		automake-1.15:devel/automake

PLIST_FILES=	share/${PORTNAME}
NO_BUILD=	yes
NO_FETCH=	yes

do-install:
	@${ECHO_CMD} "Placeholder file" > ${STAGEDIR}${PREFIX}/${PLIST_FILES}

.include <bsd.port.mk>
