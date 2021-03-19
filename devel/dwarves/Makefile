# Created by: Conrad Meyer <cem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dwarves
DISTVERSION=	1.19
CATEGORIES=	devel
MASTER_SITES=	https://fedorapeople.org/~acme/dwarves/

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Debugging Information Manipulation Tools (pahole & friends)

LICENSE=	BSD2CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/lib/bpf/LICENSE.BSD-2-Clause
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/lib/bpf/LICENSE.LPGL-2.1

IGNORE_FreeBSD_11=	inherited from dependency devel/elfutils

BUILD_DEPENDS=	gnulib>=0:devel/gnulib
LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libdw.so:devel/elfutils

USES=		cmake gettext python:3.7+,env shebangfix tar:xz
USE_GCC=	yes
USE_LDCONFIG=	yes

SHEBANG_FILES=	btfdiff fullcircle ostra/ostra-cg ostra/python/ostra.py

CFLAGS+=	-I${WRKSRC} -Wno-attributes

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

post-patch:
	${REINPLACE_CMD} -e 's,#include <malloc.h>,#include <stdlib.h>,' \
	    ${WRKSRC}/*.c
	@${MKDIR} ${WRKSRC}/asm \
	    ${WRKSRC}/bits \
	    ${WRKSRC}/linux
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/asm/bitsperlong.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/asm/errno.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/asm/posix_types.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/asm/types.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/asm/unistd.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/bits/reg.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/endian.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/exitfail.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/gettext.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/linux/limits.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/linux/types.h
	${LN} -s ${WRKSRC}/freebsd_compat.h ${WRKSRC}/vasnprintf.h

pre-configure:
	${CP} -a \
	    ${LOCALBASE}/share/gnulib/lib/obstack.c \
	    ${LOCALBASE}/share/gnulib/lib/obstack.h \
	    ${WRKSRC}
	${REINPLACE_CMD} -e 's,_GL_ATTRIBUTE_PURE,__attribute__((pure)),g' \
	    ${WRKSRC}/obstack.c ${WRKSRC}/obstack.h

.include <bsd.port.mk>
