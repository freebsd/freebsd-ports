#!/bin/sh

wrksrc=$1; prefix=$2
owner=$3; group=$4; dperm=$5; fperm=$6
plist=$7

for dir in `sed -n "s|^@dirrm ||p" $plist | sort`; do
	install -d -o ${owner} -g ${group} -m ${dperm} ${prefix}/$dir
done

for file in `sed "/^@dirrm /d; s|^eclipse/||" $plist`; do
	install -c -o ${owner} -g ${group} -m ${fperm} ${wrksrc}/${file} ${prefix}/eclipse/${file}
done
