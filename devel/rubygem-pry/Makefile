# Created by: Shin-ya MURAKAMI <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	pry
PORTVERSION=	0.9.12.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IRB alternative and runtime developer console

BUILD_DEPENDS=	rubygem-rdoc>=3.12:${PORTSDIR}/devel/rubygem-rdoc
RUN_DEPENDS=	rubygem-coderay>=1.0.5:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-method_source>=0.8:${PORTSDIR}/devel/rubygem-method_source \
		rubygem-slop>=3.4.0:${PORTSDIR}/devel/rubygem-slop

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/pry

post-patch:
	@${REINPLACE_CMD} -e "19,26 s|~>|'>='|" ${WRKSRC}/${GEM_NAME}.gemspec
	@${REINPLACE_CMD} -e '/coderay/ s|~>|>=|' ${WRKSRC}/${PORTNAME}.gemspec

.include <bsd.port.mk>
