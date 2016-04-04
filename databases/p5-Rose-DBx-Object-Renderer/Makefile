# Created by: Wen Heping
# $FreeBSD$

PORTNAME=	Rose-DBx-Object-Renderer
PORTVERSION=	0.77
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web UI Rendering for Rose::DB::Object

RUN_DEPENDS=	p5-Rose-DBx-Object-MoreHelpers>=0:databases/p5-Rose-DBx-Object-MoreHelpers \
		p5-CGI-FormBuilder>=3.05:www/p5-CGI-FormBuilder \
		p5-File-Copy-Recursive>0:devel/p5-File-Copy-Recursive \
		p5-Lingua-EN-Inflect>0:textproc/p5-Lingua-EN-Inflect \
		p5-Template-Toolkit>0:www/p5-Template-Toolkit
BUILD_DEPENDS:=	${RUN_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
