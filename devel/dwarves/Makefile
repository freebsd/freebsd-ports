PORTNAME=	dwarves
DISTVERSION=	1.31
CATEGORIES=	devel
MASTER_SITES=	https://fedorapeople.org/~acme/dwarves/

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Debugging Information Manipulation Tools (pahole & friends)
WWW=		https://acmel.wordpress.com

LICENSE=	BSD2CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/lib/bpf/LICENSE.BSD-2-Clause
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/lib/bpf/LICENSE.LGPL-2.1

EXTRACT_DEPENDS=gnulib>=0:devel/gnulib
LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libdw.so:devel/elfutils \
		libepoll-shim.so:devel/libepoll-shim
RUN_DEPENDS=	bash:shells/bash

USES=		cmake python:env shebangfix tar:xz

SHEBANG_FILES=	btfdiff fullcircle ostra/ostra-cg ostra/python/ostra.py

FAKE_HEADERS=	asm/bitsperlong.h \
		asm/byteorder.h \
		asm/errno.h \
		asm/posix_types.h \
		asm/types.h \
		asm/unistd.h \
		linux/bpf_perf_event.h \
		linux/genetlink.h \
		linux/if_ether.h \
		linux/ioctl.h \
		linux/limits.h \
		linux/ptrace.h \
		linux/rtnetlink.h \
		linux/socket.h \
		linux/stddef.h \
		linux/types.h \
		linux/version.h \
		sys/vfs.h

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

post-extract:
.for h in ${FAKE_HEADERS}
	@${MKDIR} ${WRKSRC}/$$(dirname ${h})
	${LN} -fs ${PATCHDIR}/freebsd_compat.h ${WRKSRC}/${h}
.endfor
	${CP} -a \
	    ${LOCALBASE}/share/gnulib/lib/obstack.c \
	    ${LOCALBASE}/share/gnulib/lib/libc-config.h \
	    ${LOCALBASE}/share/gnulib/lib/cdefs.h \
	    ${LOCALBASE}/share/gnulib/lib/exitfail.h \
	    ${LOCALBASE}/share/gnulib/lib/exitfail.c \
	    ${LOCALBASE}/share/gnulib/lib/gettext.h \
	    ${WRKSRC}
	${SED} -e 's|_GL_ATTRIBUTE_PURE|__attribute__ ((__pure__))|g' \
	    ${LOCALBASE}/share/gnulib/lib/obstack.in.h > \
	    ${WRKSRC}/obstack.h

.include <bsd.port.mk>
