# ex:ts=8
# Ports collection makefile for:	libmba
# Date Created:			Sep 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libmba
PORTVERSION=	0.8.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ioplex.com/~miallen/libmba/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of C modules potentially useful to any project

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
MAKE_ENV=	prefix="${PREFIX}" CC="${CC}" \
		MINVERSION="${SHLIB_MAJOR}" \
		RPM_OPT_FLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
INSTALLS_SHLIB=	yes

MAN3=		allocator.3m bitset.3m cfg.3m csv.3m diff.3m eval.3m hashmap.3m \
		hexdump.3m linkedlist.3m msgno.3m path.3m pool.3m shellout.3m \
		stack.3m suba.3m svcond.3m svsem.3m text.3m time.3m varray.3m
MANCOMPRESSED=	yes

SHLIB_MAJOR=	1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|\$${PREFIX}|g ; \
		 s|^CC|#CC|g ; \
		 s|^MAJ|#MAJ|g ; \
		 s|^MIN|#MIN|g ; \
		 s|\.\$$(MAJVERSION)||g ; \
		 s|^RPM_OPT_FLAGS|#RPM_OPT_FLAGS|g ; \
		 s| -lc| \$${LDFLAGS}|g ; \
		 s|install -m ...|\$${BSD_INSTALL_DATA}|g ; \
		 s|-/sbin/ldconfig.*$$||g ; \
		 s|-D_XOPEN_SOURCE=500||g' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
