PORTNAME=	cl-freebsd-asdf-init
PORTVERSION=	20250101
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	ASDF configuration for FreeBSD Common Lisp ports

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	etc/asdf-init.lisp \
		etc/cl-freebsd-asdf-init.lisp
SUB_FILES=	cl-freebsd-asdf-init.lisp

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.lisp ${STAGEDIR}${PREFIX}/etc/
	${RLN} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.lisp \
		${STAGEDIR}${PREFIX}/etc/asdf-init.lisp

.include <bsd.port.mk>
