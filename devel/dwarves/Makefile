# Created by: Conrad Meyer <cem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dwarves
PORTVERSION=	1.10.20160713
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	https://fedorapeople.org/~acme/dwarves/
MASTER_SITES=	http://repo.or.cz/dwarves.git/snapshot/
DISTFILES=	b52386d041fac2dc6decf3a9e8e85385784a2de9.tar.gz
# git: http://repo.or.cz/dwarves.git
# ML: http://news.gmane.org/gmane.comp.debugging.dwarves

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Debugging Information Manipulation Tools

LICENSE=	GPLv2
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

BROKEN=		does not build (/usr/local/include/libelf.h:308:8: error: unknown type name 'Elf32_Chdr')
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2017-11-09

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libdw.so:devel/elfutils
PATCH_DEPENDS=	gnulib>=0:devel/gnulib

WRKSRC=		${WRKDIR}/dwarves-b52386d

USES=		cmake:outsource localbase shebangfix tar:bzip2
USE_LDCONFIG=	yes

SHEBANG_FILES=	ostra/ostra-cg

post-patch:
	@${CP} -a \
	    ${LOCALBASE}/share/gnulib/lib/gettext.h \
	    ${LOCALBASE}/share/gnulib/lib/obstack.c \
	    ${LOCALBASE}/share/gnulib/lib/obstack.h \
	    ${WRKSRC}/
	@${REINPLACE_CMD} -e 's|_GL_ATTRIBUTE_PURE|__attribute__((__pure__))|g' \
	    ${WRKSRC}/obstack.h ${WRKSRC}/obstack.c

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1200000
IGNORE=		requires FreeBSD 12.0 (ElfNN_Chdr)
.endif

.include <bsd.port.post.mk>
