# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nomyso
PORTVERSION=	4.3
CATEGORIES=	converters devel
MASTER_SITES=	http://www.devoresoftware.com/nomyso/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert MASM/TASM files to NASM compatible sources

USES=		perl5
USE_ZIP=	yes
USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|[[:cntrl:]]$$||' \
		-e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} \
		${WRKSRC}/${PORTNAME}.pl \
		${PREFIX}/bin

.include <bsd.port.mk>
