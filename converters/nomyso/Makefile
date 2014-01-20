# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nomyso
PORTVERSION=	4.3
CATEGORIES=	converters devel
MASTER_SITES=	http://www.devoresoftware.com/nomyso/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert MASM/TASM files to NASM compatible sources

USES=		perl5
USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|[[:cntrl:]]$$||' \
		-e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} \
		${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
