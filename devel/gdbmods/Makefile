# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdbmods
PORTVERSION=	20020824
CATEGORIES=	devel
MASTER_SITES=	https://people.freebsd.org/~gallatin/
DISTFILES=	gdbmods
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for gdb -k to provide kld symbol information

LICENSE=	NONE

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/gdbmods

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
