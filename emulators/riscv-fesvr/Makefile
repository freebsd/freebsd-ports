# $FreeBSD$

PORTNAME=	riscv-fesvr
DISTVERSION=	git
PORTREVISION=	20170206
CATEGORIES=	emulators

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	RISC-V Frontend Server

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64

GH_ACCOUNT=	freebsd-riscv
GH_TAGNAME=	10a0333

USES=	gmake

HAS_CONFIGURE=	yes
USE_GITHUB=	yes
USE_LDCONFIG=	yes

STRIP_FILES=	bin/elf2hex \
		lib/libfesvr.so

post-patch:
	${REINPLACE_CMD} -e \
	's|[(]install_libs_dir[)]/pkgconfig|(INSTALLDIR)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in

post-install:
.	for f in ${STRIP_FILES}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.	endfor

.include <bsd.port.mk>
