# Created by: Steve Wills <steve@meatwad.mouf.net>
# $FreeBSD$

PORTNAME=	mkrf
PORTVERSION=	0.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Replacement to mkmf generates Rakefiles to build C Extensions

USE_RUBY=	yes
USE_PYTHON=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
post-install:
	@${REINPLACE_CMD} -e "s,{|l| \"-l#{l}\"}.join(' '),{|l| if l =~ /-/ then \"#{l}\" else \"-l#{l}\" end}.join(' ')," \
		${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION}/lib/mkrf/availability.rb
	@${RM} ${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION}/lib/mkrf/availability.rb.bak

.include <bsd.port.mk>
