PORTNAME=	jpegoptim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.6
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to optimize jpeg files
WWW=		http://www.kokkonen.net/tjko/projects.html

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		cpe gmake jpeg localbase:ldflags
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	tjko

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/jpegoptim \
		share/man/man1/jpegoptim.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^bindir =.*$$|bindir = @bindir@|g ; \
		 s|^mandir =.*$$|mandir = @mandir@|g ; \
		 s|$$(INSTALL) -m 755|$$(INSTALL_PROGRAM)|g ; \
	         s|$$(INSTALL) -m 644|$$(INSTALL_DATA)|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
