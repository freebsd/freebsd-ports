# $FreeBSD$

PORTNAME=	rdoc
PORTVERSION=	6.1.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.rdoc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.7
PLIST_FILES=	bin/rdoc bin/ri
.elif ${RUBY_VER} == 2.6
# WIP: rdoc wrapper script is installed by ruby port so far, see bug 241554, 237833
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rdoc ${STAGEDIR}${PREFIX}/bin/ri
.else
IGNORE=         ${PORTNAME} is included in lang/${RUBY_NAME}
.endif

.include <bsd.port.post.mk>
