# from https://github.com/fbergmann/libSEDML/issues/152

import libsedml

# create data set
data_set = libsedml.SedDataSet()

# set id
assert data_set.setId('obj') == 0

# check id set
assert data_set.getId() == 'obj'

# set empty name
assert data_set.setName('') == 0

# id is no longer set!
assert data_set.getId() == 'obj'

print("Test passed");
