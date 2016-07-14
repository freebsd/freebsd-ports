# Created by: Conrad Meyer <cem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dwarves
PORTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	https://fedorapeople.org/~acme/dwarves/
# http://fedorapeople.org/~acme/dwarves/%{name}-%{version}.tar.bz2
# git: http://repo.or.cz/dwarves.git
# ML: http://news.gmane.org/gmane.comp.debugging.dwarves

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Debugging Information Manipulation Tools

LICENSE=	GPLv2
LICENSE_FILE_GPLv2=	$(WRKSRC)/COPYING

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libdw.so:devel/elfutils
BUILD_DEPENDS=	cmake>=0:devel/cmake \
		gnulib>=0:devel/gnulib

# Source is a tarbomb:
WRKSRC=		$(WRKDIR)

USES=		cmake:outsource localbase tar:bzip2
USE_LDCONFIG=	yes

#CMAKE_VERBOSE=	1

post-patch:
	@${CP} -a \
	    $(LOCALBASE)/share/gnulib/lib/gettext.h \
	    $(LOCALBASE)/share/gnulib/lib/obstack.c \
	    $(LOCALBASE)/share/gnulib/lib/obstack.h \
	    $(WRKSRC)/
	@${REINPLACE_CMD} -e 's|_GL_ATTRIBUTE_PURE|__attribute__((__pure__))|g' \
	    $(WRKSRC)/obstack.h $(WRKSRC)/obstack.c

.include <bsd.port.mk>
