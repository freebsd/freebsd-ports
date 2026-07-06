import financedatabase as fd

# Initialize the Equities database
equities = fd.Equities()
print(f"equities={equities}")

# Obtain all countries from the database
print(equities.show_options('country'))

# Obtain all sectors from the database
print(equities.show_options('sector'))

# Obtain all industry groups from the database
print(equities.show_options('industry_group'))

# Obtain all industries from a country from the database
print(equities.show_options('industry', country='Germany'))

# Obtain a selection from the database
equities_united_states = equities.select(country="United States")
print(f"equities_united_states={equities_united_states}")

# Obtain a detailed selection from the database
equities_usa_electric_utilities = equities.select(country="United States", industry="Electric Utilities")
print(f"equities_usa_electric_utilities={equities_usa_electric_utilities}")

# Search specific fields from the database
equities_uk_biotech = equities.search(country='United Kingdom', summary='biotech', exchange='LSE')
print(f"equities_uk_biotech={equities_uk_biotech}")
