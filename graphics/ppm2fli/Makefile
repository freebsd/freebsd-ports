# New ports collection makefile for:	ppm2fli
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	ppm2fli
PORTVERSION=	2.0d
CATEGORIES=	graphics
MASTER_SITES=	http://vento.pi.tu-berlin.de/ppm2fli/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes

MAN1=	ppm2fli.1 unflick.1

pre-patch:
	@${PERL} -pi -e 's|^C|#C|g ; \
		 s|gcc |\$${CC} |g' ${WRKSRC}/Makefile

do-install:
.for name in ppm2fli unflick
	${INSTALL_PROGRAM} ${WRKSRC}/${name} ${PREFIX}/bin/${name}
	${INSTALL_MAN} ${WRKSRC}/${name}.man ${MANPREFIX}/man/man1/${name}.1
.endfor

.include <bsd.port.mk>
