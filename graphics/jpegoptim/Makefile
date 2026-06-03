PORTNAME=	jpegoptim
DISTVERSION=	1.5.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=   https://github.com/tjko/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to optimize jpeg files
WWW=		http://www.kokkonen.net/tjko/projects.html

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		cpe gmake jpeg localbase:ldflags
CPE_VENDOR=	${PORTNAME}_project

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
