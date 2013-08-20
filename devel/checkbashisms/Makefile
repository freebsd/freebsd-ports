# $FreeBSD$

PORTNAME=	checkbashisms
PORTVERSION=	2.0.0.2
CATEGORIES=	devel perl5
MASTER_SITES=	SF/${SF_PROJECT}/${DISTVERSION}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Script to check for Bash features not defined by POSIX

LICENSE=	GPLv2

SF_PROJECT=	checkbaskisms

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${DISTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-patch:
	@${REINPLACE_CMD} -e "s| /usr/bin/perl|${PERL}|" \
		${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
