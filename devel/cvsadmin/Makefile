PORTNAME=	cvsadmin
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	LOCAL/gabor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program to administrate users of a CVS repository

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cvsadmin \
		share/man/man1/cvsadmin.1.gz

post-configure:
	${ECHO_CMD} "#define HAVE_MKDTEMP 1" >> ${WRKSRC}/config.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/cvsadmin.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
