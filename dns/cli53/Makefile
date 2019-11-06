# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cli53
DISTVERSION=	0.8.16
CATEGORIES=	dns

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Command line tool for Amazon Route 53

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	barnybug
GH_TUPLE=	\
		aws:aws-sdk-go:v1.13.34:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-ini:ini:v1.28.2:go_ini_ini/vendor/github.com/go-ini/ini \
		gucumber:gucumber:71608e2f6e76:gucumber_gucumber/vendor/github.com/gucumber/gucumber \
		jmespath:go-jmespath:0b12d6b521d8:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		miekg:dns:e4205768578d:miekg_dns/vendor/github.com/miekg/dns \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		shiena:ansicolor:a422bbe96644:shiena_ansicolor/vendor/github.com/shiena/ansicolor \
		stretchr:testify:v1.2.1:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v1.20.0:urfave_cli/vendor/github.com/urfave/cli

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/cli53

PLIST_FILES=	bin/cli53

.include <bsd.port.mk>
