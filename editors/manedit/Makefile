# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	manedit
PORTVERSION=	1.2.1
CATEGORIES=	editors
MASTER_SITES=	http://wolfsinger.com/~wolfpack/packages/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A UNIX manual page editor and viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME=	gtk12
MAKEFILE=	Makefile.FreeBSD

MAN1=		manedit.1

pre-configure:
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/-o $$(BIN)/s/(CC)/(CXX)/' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e '/^MAN/s/.bz2//' ${WRKSRC}/Makefile.install.FreeBSD
	@${REINPLACE_CMD} -e '/^SRC_C =/s//& mntent_compat.c/' \
		${WRKSRC}/Makefile.srclist

.include <bsd.port.mk>
